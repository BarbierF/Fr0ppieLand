#ifndef NON_COPYABLE_HPP
#define NON_COPYABLE_HPP

namespace froppieLand{
    namespace modele{

        class NonCopyable{
        protected:
            NonCopyable(){}
            NonCopyable(const NonCopyable& NC){}

            NonCopyable& operator=(NonCopyable& NB) { return *this; }
        };
    }
}

#endif