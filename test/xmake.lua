add_requires("gtest", {configs = {main = false, gmock = true}})

for _, file in ipairs(os.files("src/test_*.cpp")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        add_packages("gtest")
        set_default(true)
        add_files(file)
        add_tests("default")
        add_deps("dea")
end