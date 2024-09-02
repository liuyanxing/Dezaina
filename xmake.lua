add_rules("mode.debug", "mode.release")

-- project
set_project("dezaina")

add_cxflags("/utf-8")

-- set xmake minimum version
set_xmakever("2.8.2")

-- set warning all as error
-- set_warnings("all", "error")
set_languages("cxxlatest")

option("test")
		set_default(false)
		set_showmenu(true)
		set_description("Build test")

includes("dea")
includes("test")

if not has_config("test") then
	includes("app/native")
end
