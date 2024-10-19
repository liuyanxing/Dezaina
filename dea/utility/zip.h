#pragma once

#include <vector>
#include <zlib.h>
#include <span>
#include <zstd.h>

namespace utility {

inline bool decompressZlib(std::span<char> compressedData, std::vector<unsigned char>& decompressedData) {
    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = compressedData.size();
    strm.next_in = (Bytef *)compressedData.data();

    if (inflateInit2(&strm, -15) != Z_OK) {
        return false;
    }

    size_t bufferSize = compressedData.size() * 4;
    decompressedData.resize(bufferSize);

    strm.avail_out = bufferSize;
    strm.next_out = decompressedData.data();

    int ret = inflate(&strm, Z_NO_FLUSH);
    while (ret == Z_OK || ret == Z_BUF_ERROR) {
        if (ret == Z_BUF_ERROR) {
            bufferSize *= 2;
            decompressedData.resize(bufferSize);
            strm.avail_out = bufferSize - strm.total_out;
            strm.next_out = decompressedData.data() + strm.total_out;
        }
        ret = inflate(&strm, Z_NO_FLUSH);
    }

    if (ret != Z_STREAM_END) {
        inflateEnd(&strm);
        decompressedData.clear();
        return false;
    }

    decompressedData.resize(strm.total_out);
    inflateEnd(&strm);

    return true;
}

inline bool decompressZSTD(std::span<char> compressedData, std::vector<unsigned char>& decompressedData) {
    unsigned long long decompressedSize = ZSTD_getFrameContentSize(compressedData.data(), compressedData.size());
    if (decompressedSize == ZSTD_CONTENTSIZE_ERROR) {
        return false;
    }
    if (decompressedSize == ZSTD_CONTENTSIZE_UNKNOWN) {
        return false;
    }

    decompressedData.resize(decompressedSize);

    size_t result = ZSTD_decompress(decompressedData.data(), decompressedSize, compressedData.data(), compressedData.size());
    if (ZSTD_isError(result)) {
        decompressedData.clear();
        return false;
    }

    return true;
}

}
