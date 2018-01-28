/*
Liam Ormiston
Lab8 - BinarySearchTrees
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

#include "BinarySearchTree.h"
#include "Pokemon.h"

int main(int argc, char* argv[])
{
	//Declares Variables
	std::ifstream file;
	std::string fileName;
	std::string outputFile;
	std::string aName;
	std::string pDex;
	std::string jName;
  std::string choice;
	std::string temp;
	std::string s = "";
	BinarySearchTree<Pokemon, std::string> tree;
	BinarySearchTree<Pokemon, std::string> copy;
	BinarySearchTree<Pokemon, std::string> r_tree;
	bool isCopy = false;
	bool re_move = false;

//////////////////////////////////////////////////////////////////////////////
//File opening method

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Please enter a file name: " << std::endl;
	std::cin >> fileName;
	file.open(fileName);
	while(!file.good())
	{
		std::cout << "File not valid. Please enter a valid file name: " << std::endl;
		std::cin >> fileName;
		file.open(fileName);
	}
	std::cout << "" << std::endl;

//if file isn't openable then it will prompt the user for another file until the
//user gives a valid file name
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Binary tree creation method
	while (std::getline(file,s) && !file.eof())
	{
		if(s!="")
		{
			std::istringstream ss(s);
			std::getline(ss, aName, ',');
			std::getline(ss, pDex, ',');
			std::getline(ss, jName);

			Pokemon n_Pokemon(aName, pDex, jName);
			tree.add(n_Pokemon);
		}
	}
	file.close();
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Choice menu method
	while(choice != "7")
        {
						std::cout << "---------------------------------------------------------------" << std::endl;
            std::cout << "What would you like to do?" <<std::endl;
            std::cout << "1. Search \t" << "2. Save \t" << "3. Copy \t" << "4. Add \t" << "5. Remove \t" << "6. Test \t" << "7. Quit" << std::endl;
            std::cout << "" << std::endl;
						std::cin >> choice;
						std::cout << "" << std::endl;
//////////////////////////////////////////////////////////////////////////////
//Search method
            if (choice == "1")
            {
                std::cout << "search: " << std::endl;
                std::cin >> temp;
								std::cout << "" << std::endl;

								for(unsigned int i=0; i < temp.length(); i++)
								{
									if(i==0 || temp[i-1]==' ')
									{
										temp[i]=toupper(temp[i]);
									}
									else
									{
										temp[i]=tolower(temp[i]);
									}
								}

								try
								{
									if (re_move == true)
									{
										Pokemon p = r_tree.getEntry(temp);
										aName = p.getAName();
										pDex = p.getDex();
										jName = p.getJName();
										std::cout << aName << ", " << pDex << ", " << jName << std::endl;
									}
									else
									{
										Pokemon p = tree.getEntry(temp);
										aName = p.getAName();
										pDex = p.getDex();
										jName = p.getJName();
										std::cout << aName << ", " << pDex << ", " << jName << std::endl;
									}


								}
								catch(NotFoundException n)
								{
									std::cout << n.what() << std::endl;
								}
								std::cout << "" << std::endl;
            }

//////////////////////////////////////////////////////////////////////////////
//Save method
            else if (choice == "2")
            {
							std::string order;
							std::string outfile;
							char save;
							std::ofstream o_file;
							std::cout << "---------------------------------------------------------------" <<std::endl;
							std::cout << "What is the output file name?" << std::endl;
							std::cin >> outfile;
							std::cout << "" << std::endl;
							o_file.open(outfile);

							//Helper bool to see if the user gave correct order
							bool valid = false;

							while(valid != true)
							{
								if(isCopy)
								{
									std::cout << "Which BST do you want to save, Original or the Copy? (O or C)" << std::endl;
									std::cin >> save;
									while(save != 'O' && save != 'o' && save != 'C' && save != 'c')
									{
										std::cout << "Incorrect choice, please choose O or C for Original or Copy." << std::endl;
										std::cin >> save;
									}
								}

//////////////////////////////////////////////////////////////////////////////
//Order methods
								std::cout << "How would you like to traverse? (pre, in, or post)" << std::endl;
								std::cin >> order;
								std::cout << "" << std::endl;

//Pre-order method
								if(order == "pre"|| order == "Pre")
								{
									if(save == 'C' || save == 'c')
									{
										if(re_move == true)
										{
											r_tree.pre(outfile);
										}
										else
										{
											copy.pre(outfile);
										}
										std::cout << "" << std::endl;
									}
									else
									{
										tree.pre(outfile);
										std::cout << "" << std::endl;
									}
									valid = true;
								}
//In-order method
								else if (order == "in" || order == "In")
								{
									if(save == 'C' || save == 'c')
									{
										if(re_move == true)
										{
											r_tree.in(outfile);
										}
										else
										{
											copy.in(outfile);
										}
										std::cout << "" << std::endl;
									}
									else
									{
										tree.in(outfile);
										std::cout << "" << std::endl;
									}
									valid = true;
								}
//Post-order method
								else if (order == "post" || order == "Post")
								{
									if(save == 'C' || save == 'c')
									{
										if(re_move == true)
										{
											r_tree.post(outfile);
										}
										else
										{
											copy.post(outfile);
										}
										std::cout << "" << std::endl;
									}
									else
									{
										tree.post(outfile);
										std::cout << "" << std::endl;
									}
									valid = true;
								}
//Loops back if the user doesn't give one of the 3 options
								else
								{
									std::cout << "Not a valid order, please try again." << std::endl;
								}
							}
							std::cout << "Success!" << std::endl;
							std::cout << "" << std::endl;
            }
//////////////////////////////////////////////////////////////////////////////
//Copy method
            else if (choice == "3")
            {
								file.open(fileName);
//Binary tree creation method
								while (std::getline(file,s) && !file.eof())
								{
									if(s!="")
									{
										std::istringstream ss(s);
										std::getline(ss, aName, ',');
										std::getline(ss, pDex, ',');
										std::getline(ss, jName);

										Pokemon n_Pokemon(aName, pDex, jName);
										copy.add(n_Pokemon);
									}
								}
								file.close();
								std::cout << "---------------------------------------------------------------" <<std::endl;
								std::cout << "copy success" << std::endl;
								std::cout << "" << std::endl;
								isCopy = true;
								std::cout << "" << std::endl;
            }
//////////////////////////////////////////////////////////////////////////////
//Add method

						else if (choice == "4")
						{
							std::string A_name;
							std::string dex;
							std::string J_name;

							if(!isCopy)
							{
								std::cout << "---------------------------------------------------------------" <<std::endl;
								std::cout << "You need to create a copy first!" << std::endl;
								std::cout << "" << std::endl;
							}
							else
							{
								std::cout << "---------------------------------------------------------------" <<std::endl;
								std::cin.ignore();
								std::cout << "American name: ";
								std::getline (std::cin, A_name);
								std::cout << "Pokedex number: ";
								std::cin >> dex;
								std::cin.ignore();
								std::cout << "Japanese name: ";
								std::getline (std::cin, J_name);
								J_name = J_name+"\n";

								Pokemon add_P(A_name, dex, J_name);
								if(re_move == true)
								{
									r_tree.add(add_P);
								}
								else
								{
									copy.add(add_P);
								}
								std::cout << "" << std::endl;
							}
						}
//////////////////////////////////////////////////////////////////////////////
//Remove method
						else if (choice == "5")
						{
							std::string s;
							if(!isCopy)
							{
								std::cout << "---------------------------------------------------------------" <<std::endl;
								std::cout << "You need to create a copy first!" << std::endl;
								std::cout << "" << std::endl;
							}
							else
							{

								std::cout << "---------------------------------------------------------------" <<std::endl;

								std::cout << "The Pokemon you want to remove: " << std::endl;
								std::cin >> temp;

								std::cout << "" << std::endl;

								for(unsigned int i=0; i < temp.length(); i++)
								{
									if(i==0 || temp[i-1]==' ')
									{
										temp[i]=toupper(temp[i]);
									}
									else
									{
										temp[i]=tolower(temp[i]);
									}
								}
								bool exception = false;
								std::string s;
								ifstream filein(fileName);
								ofstream fileout("outputF.txt");
								std::string strTemp;
								try
								{
									Pokemon p_rem = tree.getEntry(temp);
									std::string a = p_rem.getAName()+", "+p_rem.getDex()+", "+p_rem.getJName();

							    while(std::getline(filein,strTemp) && !filein.eof())
							    {
						        if(strTemp == a)
										{
					            strTemp = s;
						        }
						        strTemp += "\n";
						        fileout << strTemp;
							    }
									filein.close();
									fileout.close();
								}
								catch (NotFoundException e)
								{
									std::cout << e.what() << std::endl;
									exception = true;
								}
								filein.open("outputF.txt");
								while (std::getline(filein,s) && !filein.eof())
								{
									if(s!="")
									{

										std::getline(filein, aName, ',');
										std::getline(filein, pDex, ',');
										std::getline(filein, jName);

										Pokemon n_Pokemon(aName, pDex, jName);
										r_tree.add(n_Pokemon);
									}
								}
								if(exception == false)
								{
									std::cout << "Removing the pokemon was a success!" << std::endl;
								}
								filein.close();
								re_move = true;
								remove("outputF.txt");
								std::cout << "" << std::endl;
							}
						}
//////////////////////////////////////////////////////////////////////////////
//Test method
						else if (choice == "6")
						{
							char num = '\0';
							BinarySearchTree<Pokemon, std::string> r_tree;
							bool rem = false;

							while( num != '4')
							{
								std::cout << "---------------------------------------------------------------" <<std::endl;
								std::cout << "What test method would you like to run? (Please choose a number)" << std::endl;
								std::cout << "1. Add" << std::endl;
								std::cout << "2. Remove" << std::endl;
								std::cout << "3. Write to file" << std::endl;
								std::cout << "4. Exit Test Mode" << std::endl;
								std::cin >> num;
								std::cout << "" << std::endl;

								if(num == '1')
								{
									std::string A_name;
									std::string dex;
									std::string J_name;

									std::cout << "---------------------------------------------------------------" <<std::endl;
									std::cin.ignore();
									std::cout << "American name: ";
									std::getline (std::cin, A_name);

									for(unsigned int i=0; i < A_name.length(); i++)
									{
										if(i==0 || A_name[i-1]==' ')
										{
											A_name[i]=toupper(A_name[i]);
										}
										else
										{
											A_name[i]=tolower(A_name[i]);
										}
									}

									std::cout << "Pokedex number: ";
									std::cin >> dex;
									std::cin.ignore();
									std::cout << "Japanese name: ";
									std::getline (std::cin, J_name);

									for(unsigned int i=0; i < J_name.length(); i++)
									{
										if(i==0 || J_name[i-1]==' ')
										{
											J_name[i]=toupper(J_name[i]);
										}
										else
										{
											J_name[i]=tolower(J_name[i]);
										}
									}

									Pokemon add_P(A_name, dex, J_name);
									if(rem == false)
									{
										tree.add(add_P);
										tree.print_in();
									}
									else
									{
										r_tree.add(add_P);
										r_tree.print_in();
									}

									std::cout << "" << std::endl;
								}

//////////////////////////////////////////////////////////////////////////////
//Remove test function
								else if (num == '2')
								{
									bool exception = true;
									std::cout << "---------------------------------------------------------------" <<std::endl;
									std::string s;
									ifstream filein(fileName);
									ofstream fileout("outputF.txt");
									std::string strTemp;
									while(exception == true)
									{
										std::cout << "The Pokemon you want to remove: " << std::endl;
										std::cin >> temp;

										std::cout << "" << std::endl;

										for(unsigned int i=0; i < temp.length(); i++)
										{
											if(i==0 || temp[i-1]==' ')
											{
												temp[i]=toupper(temp[i]);
											}
											else
											{
												temp[i]=tolower(temp[i]);
											}
										}

											try
											{
												Pokemon p_rem = tree.getEntry(temp);
												std::string a = p_rem.getAName()+", "+p_rem.getDex()+", "+p_rem.getJName();
												while(std::getline(filein,strTemp) && !filein.eof())
												{
													if(strTemp == a)
													{
														strTemp = s;
													}
													strTemp += "\n";
													fileout << strTemp;
													exception = false;
												}
											}
											catch(NotFoundException e)
											{
												std::cout << e.what() << std::endl;
											}
										}
										filein.close();
										fileout.close();
										filein.open("outputF.txt");
										while (std::getline(filein,s) && !filein.eof())
										{
											if(s!="")
											{
												std::getline(filein, aName, ',');
												std::getline(filein, pDex, ',');
												std::getline(filein, jName);

												Pokemon n_Pokemon(aName, pDex, jName);
												r_tree.add(n_Pokemon);
												rem = true;
											}
										}
										filein.close();
										r_tree.print_in();
										remove("outputF.txt");
										std::cout << "" << std::endl;
								}
//////////////////////////////////////////////////////////////////////////////
//Write test function
								else if (num == '3')
								{
									std::cout << "---------------------------------------------------------------" <<std::endl;
									std::cout << "Name of output file: " << std::endl;
									cin >> outputFile;
									if(rem == true)
									{
										r_tree.in(outputFile);
									}
									else
									{
										tree.in(outputFile);
									}
									std::cout << "Success!" << std::endl;
									std::cout << "" << std::endl;
								}
								else if (num == '4')
								{
									std::cout << "---------------------------------------------------------------" <<std::endl;
									std::cout << "Exiting Test Mode..." << std::endl;
									std::cout << "Done." << std::endl;
									std::cout << "" << std::endl;
								}
								else
								{
									std::cout << "Invalid choice. Please choose a valid number." << std::endl;
									std::cout << "" << std::endl;
								}
							}
						}
//////////////////////////////////////////////////////////////////////////////
//Quit method
						else if (choice == "7")
						{
							std::cout << "Thank you!" << std::endl;
							std::cout << "" << std::endl;
							std::cin.ignore();
						}

//////////////////////////////////////////////////////////////////////////////
//Prompt if the user doesn't give a correct choice
            else
            {
                std::cout << "I'm sorry, that isn't a valid option. Please try again." << std::endl;
            }
//Takes user back to the top of the while loop
        }

	return 0;
}
