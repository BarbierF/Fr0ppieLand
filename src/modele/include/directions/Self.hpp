#ifndef SELF_DIR_HPP
#define SELF_DIR_HPP

namespace froppieLand{
    namespace modele{

        class Self: public Direction{

        public:
            static const Self& getSelf();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            Self(const Self& ) = delete;
            Self& operator=(const Self& ) = delete;

        private:
            Self();

            static const Self _self;
        };
    }
}

#endif