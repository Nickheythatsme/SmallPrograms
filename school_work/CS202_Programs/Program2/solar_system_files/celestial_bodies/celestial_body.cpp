#include "celestial_body.h"
/* Nicholas Grout
 * Program 1
 */

int celestial_body::return_distance(void) const
{
    return -1;
}
//This function display the infomation for this celestial body.
void celestial_body::display(void) const
{
    //We use setw() because that ensures our data is centered and displayed
    //neatly.
    cout << endl;
    display("Name", name);
    display("Diameter", diameter, "miles");
    return;
}

void celestial_body::display(const char * var, int value, const char * unit) const
{
    if( !var ) return;
    set_cout();
    if( !unit )
        cout << var << value << endl;
    else
        cout << var << value << ' ' << unit << endl;
    return;
}

void celestial_body::display(const char * var, float value, const char * unit) const
{
    if( !var ) return;
    set_cout();
    if( !unit )
        cout << var << value << endl;
    else
        cout << var << value << ' ' << unit << endl;
    return;
}

void celestial_body::display(const char * var, char * value, const char * unit) const
{
    if( !var || !value ) return;
    set_cout();
    if( !unit )
        cout << var << value << endl;
    else
        cout << var << value << ' ' << unit << endl;
    return;
}

void celestial_body::set_cout() const
{
    cout.setf(ios::left);
    cout.width(BUFFER);
    cout.fill('-');
    cout.precision(4);

    return;
}

//Constructor is implemented here:
celestial_body::celestial_body(const char * new_name, float new_diameter)
{
    //Copy the array of characters for the name here:
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);

    //Copy the new diameter here:
    diameter = new_diameter;
}

//Copy constructor is implemented here:
celestial_body::celestial_body(const celestial_body & obj)
{
    //Copying the array of characters from obj to this class's name here:
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

    //Copying the diameter here:
    diameter = obj.diameter;

}

//Deconstructor is implemented here:
celestial_body::~celestial_body()
{
    //Name definitely exists so this is okay.
    delete [] name;
    name = NULL;
}

