fips_begin_app(sova-test-app windowed)
    fips_vs_warning_level(3)
    fips_files(
            Main.cpp
            Controller.h
            TestShaderHandler.h TestShaderHandler.cpp
            Global.h
    )
    oryol_shader(shaders.shd)
    fips_deps(Sova)
fips_end_app()