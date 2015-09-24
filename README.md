# ini_parser
A small bare bones ini-file parser in C++

## Usage

    #include <fstream>
    #include "ini_parser.h"
    
    // Doesn't have to be an istream; any readable stream works
    std::istream myConfigFileStream;
    Ini::Parser parser (&myConfigFileStream);
    parser.scan();
    
When you're ready to consume the values of the config file you'll find the *last section header* in `Ini::Parser::current_section`;
like so

    Ini::Section section = *parser.current_section;
    
The `Ini::Section` class is a *double linked list*. Use `Ini::Section::previous` and `Ini::Section::next`
to get at the previous and next sections, respectively. To get at the first section header, you might want to:

    while (section.previous)
        section = section.previous;
        
### Keys and values
To get the keys and values you've recorded in your config files, use `Ini::Parser::lines`, which is a vector containing a <string, string> pair;

    std::vector< std::pair<std::string, std::string> > lines;
    
In other words, to get the first key-value pair of a section, use `section.lines[0].first` and `section.lines[0].second`. 
Or, you know, iterate over the lines.

### Syntax
The syntax of the config file itself is incredibly simple:

    [A section header]
    key=value
    
Newlines are possible (between sections and values, not in them), as well as spaces and special characters (in the sections and values).

### Comments
To create a comment (i.e. content that the parser doesn't consume), just type something after your section header:

    [A section header] This is a comment!
    key=value
    
Anything after the closing `]` bracket (except for newlines) are discarded by the parser, including special characters and what not*.

### Memory
If you `delete` the parser you delete `current_section`. Set the pointer to null if you don't want it to handle it for you.

If you `delete` a *section*, you delete the whole section chain as well. Set the `next` and `previous` pointers to null if you want to handle it yourself.

##### * No securing of the indata is done, so expect trouble if you throw a binary blob at it.

## Todo
* Better in-source documentation

~* Break out `current_section` into getters and setters and instantiate it lazily.~
