add_executable(circle
        circle.c )
add_executable(sphere
        sphere.c )
add_executable(mol
        mol.c)

add_executable(admin
        admin.c)
target_link_libraries(admin m)

add_executable(admin-scanf
        admin-scanf.c)
target_link_libraries(admin-scanf m)