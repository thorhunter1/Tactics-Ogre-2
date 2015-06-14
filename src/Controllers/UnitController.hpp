#ifndef UNIT_CONTROLLER_HPP
#define UNIT_CONTROLLER_HPP

#include <map>
#include "Controllers/Controlled.hpp"

class UnitController
{
    public:

        int addUnit( Unit* unit );

        



    private:
        
        std::vector< controlled< Unit*> >  unitList_;
};

#endif //UNIT_CONTROLLER_HPP
