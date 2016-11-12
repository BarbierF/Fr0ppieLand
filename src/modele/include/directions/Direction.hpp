#ifndef DIRECTION_HPP
#define DIRECTION_HPP


namespace froppieLand{
    namespace modele{
        /**
         * Classe de Direction
         */
        class Direction{
        public:
            /**
             * Composante X du vecteur de direction
             * @return la composante X
             */
            virtual const int getVectorXDirection()const = 0;

            /**
             * Composante Y du vecteur de direction
             * @return la composante Y
             */
            virtual const int getVectorYDirection()const = 0;
        };
    }
}

#endif