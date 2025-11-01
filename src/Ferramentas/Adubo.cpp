//
// Created by Rodrigo on 31/10/2025.
//

#include "Adubo.h"

#include "../Settings.h"

Adubo::Adubo():Ferramenta('a', "Abubo") {
    usosResteantes=Settings::Adubo::capacidade;

}
