#ifndef NOMSTATE_HPP
#define NOMSTATE_HPP

class NomState{
		public:
				virtual const NomState& get_instance()=0;
				virtual const int& get_size()const=0;
		protected:
				NomState* _instance;
};

#endif
