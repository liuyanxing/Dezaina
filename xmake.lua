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
option_end()

option("app")
		add_deps("render")
		set_default(false)
		set_showmenu(true)
		set_description("Build app")
option_end()

includes("dea")

includes("test")

if has_config("app") then
	includes("app/native")
end

includes("app/helloworld")
