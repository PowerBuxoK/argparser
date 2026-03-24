# ARGPARSER

## Usage

The library workspace is located in `arp`

- To start working with the library you need
to create a `arp::Argparser` object, which takes
argc and argv as arguments.

- `--help` is automatically generated.

- To add an argument to `arp::Argparser` you need
to call `.add<argument type>` on it.
This returns a smart pointer to an instance of the argument.

- `arp::Argparser.add<argument type>(string name, string description, is required, is positional)`

- Positional arguments are read in the same order they are defined in.

- After the setup is complete you **need**
to call `arp::Argparser.parse()`.

##### Possible argument types
- `arp::sint` : signed integer
- `arp::str` : string
- `arp::def` : is argument defined

### Code example:

```cpp
#include "argparser.cpp" // Include argparser


int main(int argc, char* argv[])
{
  arp::Argparser ap(argc, argv); // Initialize the main object
  // Set the program description
  ap.setDesription("Test program buru :3");
  // Add a required positional argument named argname0
  auto arg0 = ap.add<arp::sint>("argname0", "Argument 0", arp::required, arp::pos);
  // Add a required positional argument named argname1
  auto arg1 = ap.add<arp::str>("argname1", "Argument 1", arp::required, arp::pos);
  // Add a required non-positional argument named argname2
  auto arg2 = ap.add<arp::def>("--argname2", "Argument 2", arp::required, arp::nopos);
  ap.parse();

  std::cout << arg0->val() << std::endl;
  std::cout << arg1->val() << std::endl;
  // These two lines are the same because type is arp::def
  std::cout << arg2->val() << std::endl;
  std::cout << arg2->defined() << std::endl;
  return 0;
}
```
