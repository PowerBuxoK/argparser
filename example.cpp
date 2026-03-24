#include "argparser.cpp"
#include <iostream>
#include <string>

/* TODO:
 * Add required handsling
 */

int main(int argc, char* argv[])
{
  arp::Argparser ap(argc, argv);
  ap.setDesription("Test program buru :3");
  auto arg0 = ap.add<arp::sint>("argname0", "Argument 0", arp::required, arp::pos);
  auto arg1 = ap.add<arp::str>("argname1", "Argument 1", arp::required, arp::pos);
  auto arg2 = ap.add<arp::def>("--argname2", "Argument 2", arp::required, arp::nopos);
  ap.parse();

  std::cout << arg0->val() << std::endl;
  return 0;
}
