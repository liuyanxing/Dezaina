target("helloworld")
	set_kind("binary")
	add_files("*.cpp")
	add_deps("dea")
	set_rundir("$(projectdir)")