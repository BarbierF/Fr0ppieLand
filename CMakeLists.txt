# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

#Nom du projet
PROJECT ( Fr0ppieLand )


FIND_PACKAGE( PkgConfig REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( 	src/modele/include
						src/modele/include/froppie
						src/modele/include/froppie/fropEtat
						src/modele/include/nenuphar
						src/modele/include/nenuphar/strategy
						src/modele/include/nenuphar/surfEtat
						src/modele/include/directions
						src/presentateur/include
						src/vue/include
						${GTKMM_INCLUDE_DIRS}	
					)



# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

LINK_LIBRARIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( froppieland 
	src/modele/NenuVieillissant.cpp
	src/modele/NenuNonVieillissant.cpp
	src/modele/Petit.cpp
	src/modele/Moyen.cpp
	src/modele/Grand.cpp
	src/modele/Inexistant.cpp
	src/modele/Dopant.cpp
	src/modele/Eau.cpp
	src/modele/Immortel.cpp
	src/modele/Mortel.cpp
	src/modele/Normal.cpp
	src/modele/Nutritif.cpp
	src/modele/Veneneux.cpp
	src/modele/FactoryStrategyNenuphar.cpp
	src/modele/IterVoisin.cpp
	src/modele/Surface.cpp
	src/modele/Nord.cpp
	src/modele/Sud.cpp
	src/modele/Ouest.cpp
	src/modele/Est.cpp
	src/modele/Sain.cpp
	src/modele/Malade.cpp
	src/modele/Mort.cpp
	src/modele/Froppie.cpp
	src/modele/Grill.cpp
	src/vue/FroppieVue.cpp
	src/vue/GCaseMare.cpp
	src/vue/GGrill.cpp
	src/vue/FroppHealth.cpp
	src/vue/ResolutionFL.cpp
	src/vue/BarreChrono.cpp
	src/presentateur/Presentateur.cpp

	src/main.cpp 

)



set( CMAKE_VERBOSE_MAKEFILE off )

