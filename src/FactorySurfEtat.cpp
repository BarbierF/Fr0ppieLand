#include "FactorySurfEtat.hpp"


const SurfEtat& froppieLand::modele::FactorySurfEtat::getInexistant() {
    if(!_inexistant){
        _inexistant = new froppieLand::modele::Inexistant();
    }
    return _inexistant;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getGrand() {
    if(!_grand){
        _grand = new froppieLand::modele::grand();
    }
    return _grand;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getMoyen() {
    if(!_moyen){
        _moyen = new froppieLand::modele::moyen();
    }
    return _moyen;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getPetit() {
    if(!_petit){
        _petit = new froppieLand::modele::petit();
    }
    return _petit;
}
