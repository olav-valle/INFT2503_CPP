#include <gtkmm.h>
#include <iostream>

// Oppg 4.2
// Ta utgangspunkt i https://gitlab.com/ntnu-iini4003/gtkmm-example
// og lag eit lite program som slår sammen inntastet fornavn og etternavn
// når du klikker på en knapp. Knappen skal kun være sensitiv når både
// fornavn og etternavn er tastet inn, og grået ut ellers (ikke sensitiv).
// Sett også tittel på vinduet.

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label label_first_name;
  Gtk::Entry entry_first_name;

  Gtk::Label label_last_name;
  Gtk::Entry entry_last_name;

  Gtk::Button button;
  Gtk::Label label;

  Window() {
    Gtk::Window::set_title("Combine Names");
    button.set_sensitive(false);
    button.set_label("Combine Names");

    label_first_name.set_text("First Name:");
    vbox.pack_start(label_first_name); // Add the widget label entry to vbox
    vbox.pack_start(entry_first_name); // Add the widget entry to vbox

    label_last_name.set_text("Last Name:");
    vbox.pack_start(label_last_name); // Add the widget label entry to vbox
    vbox.pack_start(entry_last_name); // Add the widget entry to vbox

    vbox.pack_start(button); // Add the widget button to vbox
    vbox.pack_start(label);  // Add the widget label to vbox
    add(vbox);               // Add vbox to window
    show_all();              // Show all widgets

    // I should probably try to find a way to handle both input checks in one lambda, but ran out of time... Sorry!
    entry_first_name.signal_changed().connect([this]() {
      button.set_sensitive(
          !entry_first_name.get_text().empty() && !entry_last_name.get_text().empty());
    });

    entry_last_name.signal_changed().connect([this]() {
      button.set_sensitive(
          !entry_first_name.get_text().empty() && !entry_last_name.get_text().empty());
    });

    button.signal_clicked().connect([this]() {
      label.set_text("Names combined: " + entry_first_name.get_text() + " " + entry_last_name.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
