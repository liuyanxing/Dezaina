includes("xmake/option.lua")
includes("xmake/package.lua")
--  includes("node")

set_languages("cxx20")

target("dea")
		add_packages("nlohmann_json", "spdlog", {public = true})
    -- add_deps("genNode")

    -- make as a static/shared library
    set_kind("static")

    -- add include directories
    add_includedirs(".", {public = true})
    add_files("*.cpp")

    -- add sub directories
    local subdirs = {"base", "change", "config", "hotkey", "primitives", "schema", "utility", "viewport", "geometry"}
    local modules = {"command", "document", "event", "interaction", "layout", "node", "resource"}

    if (has_config("render")) then
        add_packages("skia", {public = true})
        table.insert(modules, "render")
        add_defines("DEA_ENABLE_RENDER")
    end

    for _, name in ipairs(subdirs) do
			add_files("./"..name.."/*.cpp")
    end
		-- add sub modules
    for _, name in ipairs(modules) do
        -- add_files("./$(name)/src/*.cpp")
        add_files("./" .. name .. "/*.cpp")
        add_includedirs("./" .. name .. "/include", {public = true})
    end
