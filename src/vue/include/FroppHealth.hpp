#ifndef FROPP_HEALTH_HPP
#define FROPP_HEALTH_HPP

#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>

#include <memory>


namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    };

    namespace vue{

        class FroppieVue;

        class FroppHealth: public Gtk::Frame{

        public:

            friend class FroppieVue;

        public:

            FroppHealth(FroppieVue& vue, Glib::ustring titre);

            FroppHealth(const FroppHealth&) = delete;

            FroppHealth& operator=(const FroppHealth&) = delete;

            const Gtk::Image& getImage()const;

        protected:

            void setImage(const presentateur::Presentateur& presentateur, 
                const Glib::ustring& image);

            void majFroppHealth(const presentateur::Presentateur& presentateur);
        
        protected:

            FroppieVue& _vue; 

            std::unique_ptr < Gtk::Image > _coeur;

            Gtk::Label _labelPdv;

            Gtk::HBox _manager;

        };
    }
}

#endif