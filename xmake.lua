-- project
set_project("dezaina")

-- set xmake minimum version
set_xmakever("2.8.2")

-- set warning all as error
-- set_warnings("all", "error")
set_languages("cxx20")

includes("dea")
includes("app/native")
