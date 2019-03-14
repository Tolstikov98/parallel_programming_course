message(STATUS "Task 1")

SUBDIRLIST(subdirs ${CMAKE_CURRENT_SOURCE_DIR})

<<<<<<< HEAD
foreach(subd ${subdirs})
  add_subdirectory(${subd})
endforeach()
=======

foreach(subd ${subdirs})
  
	add_subdirectory(${subd})

endforeach()
>>>>>>> fix conflict
