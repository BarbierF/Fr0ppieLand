# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Création des exécutables.
ADD_EXECUTABLE( froppieland 
	src/main.cpp 
)

ADD_EXECUTABLE( SurfEtat
		src/Inexistant.cpp
		src/Grand.cpp
		src/Moyen.cpp
		src/Petit.cpp
)
ADD_EXECUTABLE( StrategyNenuphar
		src/main.cpp
		src/FactoryStrategyNenuphar.cpp
		src/SurfCanDie.cpp
		src/SurfCannotDie.cpp
		src/Eau.cpp
		src/Immortel.cpp
		src/Veneneux.cpp
		src/Normal.cpp
		src/Dopant.cpp
		src/Nutritif.cpp
		src/Mortel.cpp
)


# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

