/*
 * Nicholas Grout
 * Program 3
 */
#include "event.h"
#include "tree.h"

#define TEMP 1000

bool test_contact(void);
bool test_event(void);
bool test_tree(void);

int read_in(char * file_name, tree & tree_obj);

int main(int argc, char * argv[])
{
    tree tree_obj;
    read_in(argv[1],tree_obj);
    return 0;
}

int read_in(char * file_name, tree & tree_obj)
{
    if(!file_name) return 0;
    char temp_keyword[TEMP];
    text temp_text;
    event * temp_event = NULL;
    enode * temp_enode = NULL;
    ifstream fin(file_name,ifstream::in);

    TwoThreeTree<char> test_tree;

    //while( !fin.eof() )
    for(int i = 0; i < 3; ++i)
    {
        temp_event = new event;
        fin >> *temp_event;

        do{
            fin.get(temp_keyword, TEMP, ',');
            fin.ignore(TEMP,',');
            temp_text = text(temp_keyword);
            cout << temp_keyword[0] << endl;
            temp_enode = new enode(*temp_event, temp_text);
            test_tree.insert(temp_keyword[0]);
            tree_obj.insert(*temp_enode);
            cout << *temp_enode << endl;
            delete temp_enode;
        }while( fin.peek() != '\n' && !fin.eof() );

        if( !fin.eof() )
            fin.ignore(TEMP,'\n');
        delete temp_event;
        cout << test_tree << endl;
    }

    temp_enode = NULL;
    temp_event = NULL;

    return 1;
}

bool test_event(void)
{
    event test_e("Graduation", "PSU", 400);
    contact contact1("Nick","503-956-6343");
    contact contact2("Haley","541-234-5678");

    test_e << contact1 << contact2;
    test_e.insert_keyword("grad");
    test_e.insert_keyword("finally");
    test_e.insert_keyword("long");
    test_e.insert_keyword("boring");
    test_e.insert_comment("This event is the silliest thing I've ever seen");
    test_e.insert_comment("Never going to happen");
    cout << test_e << endl;

    ++test_e["Nick"];
    cout << test_e["Haley"] << endl;
    cout << test_e["Nick"] << endl;
    return true;
}

bool test_contact(void)
{
    contact contact1("Nick","503-956-6343");
    contact contact2("Haley","541-234-5678");
    contact contact3;

    contact_group new_group;
    new_group << contact2 << contact1;

    cout << new_group << endl;

    new_group >> contact3;

    cout << endl;
    cout << new_group << endl;

    return true;
}
