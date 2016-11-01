#ifndef SELF_DIR_HPP
#define SELF_DIR_HPP

namespace froppieLand{
    namespace modele{

        class Self: public Direction{

        public:
            static const Seld& getSelf();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

        private:
            Self();

            static const Self _self;
        }
    }
}

#endif