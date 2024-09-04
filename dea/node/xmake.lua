target("genNode")
	set_kind("phony")
	on_build(function(target)
			local scriptdir = target:scriptdir() .. "/tool"
			os.cd(scriptdir)
			os.vrunv("node", {"./generate-node-defination.js"})
		end
	)