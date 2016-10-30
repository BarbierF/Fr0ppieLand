# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )

PROJECT ( FroppieLand )
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( 	src/include
						src/include/froppie
						src/include/nenuphar/strategy
						src/include/nenuphar/surfEtat
						src/include/directions )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Création des exécutables.
ADD_EXECUTABLE( froppieland 
	src/main.cpp 
)



set( CMAKE_VERBOSE_MAKEFILE off )

