void ListaPersona::inicializarListaP(Persona*& personas)
{
	Persona* nuevo = new Persona(_nombre, _apellido, _cedula);
	string line;
    fstream out;
    out.open("listaPersona.txt", fstream::in);
    ifstream myfile("listaPersona.txt");
    if (myfile.is_open())
   {
		while (getline(myfile, line))
		{
			//string word = line.substr(0, line.find("/"));
			//string meaning = line.substr(line.find("/") + 1, line.length());
			//insert(tree, word, meaning, NULL);
			_nombre = line.substr(0, line.find(","));
			_apellido = line.substr(line.find(",")+1,line.length());
			_cedula = line.substr(_apellido) + 2, line.length();
		
       }
       myfile.close();
       out.close();