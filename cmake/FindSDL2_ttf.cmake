# Recherche la bibliothèque SDL2_ttf
# Cette module recherche la bibliothèque SDL2_ttf et définit les variables
# SDL2_TTF_FOUND - vrai si la bibliothèque SDL2_ttf est trouvée
# SDL2_TTF_INCLUDE_DIRS - les répertoires d'en-tête pour SDL2_ttf
# SDL2_TTF_LIBRARIES - les bibliothèques à lier pour SDL2_ttf
#
# Une fois cela inclus, vous pouvez utiliser
#    find_package(SDL2_ttf REQUIRED)
# pour trouver la bibliothèque SDL2_ttf.
#

# Le répertoire contenant le fichier SDL2_ttf.h
# Cela peut être défini avec la variable d'environnement SDL2_TTF_DIR.
if (NOT SDL2_TTF_INCLUDE_DIRS)
    if (DEFINED ENV{SDL2_TTF_DIR})
        list(APPEND CMAKE_PREFIX_PATH "/usr/include/SDL2")
    endif ()
    find_path(SDL2_TTF_INCLUDE_DIRS SDL2/SDL_ttf.h)
endif ()

# Les bibliothèques à lier
# Cela peut être défini avec la variable d'environnement SDL2_TTF_LIBRARY.
if (NOT SDL2_TTF_LIBRARIES)
    if (DEFINED ENV{SDL2_TTF_LIBRARY})
        list(APPEND CMAKE_LIBRARY_PATH "/usr/lib/x86_64-linux-gnu")
    endif ()
    find_library(SDL2_TTF_LIBRARIES NAMES SDL2_ttf)
endif ()

# Le résultat
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2_ttf DEFAULT_MSG SDL2_TTF_LIBRARIES SDL2_TTF_INCLUDE_DIRS)
