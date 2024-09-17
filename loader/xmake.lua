add_requires("zlib", "minizip")

target("loader")
	add_packages("zlib", "minizip")
	set_kind("static")
	add_includedirs("include", {public = true})
	add_files("src/*.cpp")