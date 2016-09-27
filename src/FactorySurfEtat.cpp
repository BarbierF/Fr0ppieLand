#include "FactorySurfEtat.hpp"


const SurfEtat& froppieLand::modele::FactorySurfEtat::getInexistant() {
    if(!froppieLand::modele::FactorySurfEtat::_inexistant){
        froppieLand::modele::FactorySurfEtat::_inexistant = new froppieLand::modele::Inexistant();
    }
    return froppieLand::modele::FactorySurfEtat::_inexistant;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getGrand() {
    if(!froppieLand::modele::FactorySurfEtat::_grand){
        froppieLand::modele::FactorySurfEtat::_grand = new froppieLand::modele::grand();
    }
    return froppieLand::modele::FactorySurfEtat::_grand;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getMoyen() {
    if(!froppieLand::modele::FactorySurfEtat::_moyen){
        froppieLand::modele::FactorySurfEtat::_moyen = new froppieLand::modele::moyen();
    }
    return froppieLand::modele::FactorySurfEtat::_moyen;
}

const SurfEtat& froppieLand::modele::FactorySurfEtat::getPetit() {
    if(!froppieLand::modele::FactorySurfEtat::_petit){
        _froppieLand::modele::FactorySurfEtat::petit = new froppieLand::modele::petit();
    }
    return _froppieLand::modele::FactorySurfEtat::petit;
}
