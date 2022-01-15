doxygen = find_program('doxygen', required : false)
if doxygen.found()
    message('Doxygen found')
    run_target('documentation', command : 'make_documentation.sh')
else
    warning('Documentation disabled without doxygen')
endif