add_rules("mode.debug", "mode.release")

-- project
set_project("dezaina")

-- set xmake minimum version
set_xmakever("2.8.2")

-- set warning all as error
-- set_warnings("all", "error")
set_languages("cxxlatest")

includes("dea")
includes("app/native")
