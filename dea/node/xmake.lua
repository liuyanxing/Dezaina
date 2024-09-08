-- rule("build_node")
--     set_extensions(".js")

--     on_buildcmd_file(function (target, batchcmds, sourcefile, opt)
--         import("lib.detect.find_tool")
--         local node = assert(find_tool("node"), "node not found")

--         local args = {path(sourcefile)}
--         batchcmds:vrunv(node.program, args)

--         -- add deps
--         batchcmds:add_depfiles(sourcefile, "tool/**.js", "tool/**.mustache")
--     end)
-- rule_end()

-- target("genNode")
-- 	set_kind("object")
--     add_rules("build_node")
--     add_files("./tool/generate-node-defination.js")