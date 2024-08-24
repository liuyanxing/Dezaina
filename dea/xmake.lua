includes("xmake/package.lua")

set_languages("cxx20")

target("dea")
		add_packages("skia", "nlohmann_json", "spdlog", {public = true})

    -- make as a static/shared library
    set_kind("static")

    -- add include directories
    add_includedirs(".", {public = true})
    add_files("*.cpp")

    -- add sub directories
    for _, name in ipairs({"common", "config", "geometry", "hotkey", "primitives", "schema", "utility", "viewport"}) do
			add_files("./"..name.."/*.cpp")
    end

		-- add sub modules
    for _, name in ipairs({"command", "document", "event", "interaction", "layout", "node", "render", "resource"}) do
        -- add_files("./$(name)/src/*.cpp")
        add_files("./" .. name .. "/src/*.cpp")
        add_includedirs("./" .. name .. "/include", {public = true})
    end
