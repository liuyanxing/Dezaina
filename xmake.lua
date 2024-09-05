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
		set_default(true)
		set_showmenu(true)
		set_description("Build test")

includes("dea")

if has_config("test") then
	includes("test")
else
	includes("app/native")
end
