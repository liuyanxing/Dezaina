task("vs")
    on_run(function ()
        os.exec("xmake project -k vsxmake -m \"debug,release\"")
    end)
    set_menu {
        usage = "xmake test",
        description = "Print hello xmake!"
    }
task_end()