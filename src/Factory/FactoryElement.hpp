#ifndef FACTORY_ELEMENT_HPP
#define FACTORY_ELEMENT_HPP

class FactoryElement
{
    friend class TileFactory;
    friend class TileCompositeFactory;
    friend class UnitFactory;

    protected:

        unsigned int getID() { return ID_; }

    private:

        unsigned int ID_;
};

#endif //FACTOY_ELEMENT_HPP
