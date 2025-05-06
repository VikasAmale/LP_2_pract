 #include <iostream>
#include <string>

 using namespace std;
 int main()
 {
 	string input;
 	cout << "Hello! I am chatbot?" << endl;
 	while (true)
 	{
 		// Get user input
 		cout << "You: ";
 		getline(cin, input);


 		// Convert to lowercase for simple matching
 		for (int i = 0; i < input.length(); i++)
 		{
 			input[i] = tolower(input[i]);
 		}



 		// Respond based on input
 		if (input == "hi" || input == "hello")
 		{
 			cout << "Chatbot: Hello! How can I help you?" << endl;
 		}
 		else if (input == "bye")
 		{
 			cout << "Chatbot: Goodbye! Have a great day!" << endl;
 			break;
 		}
 		else if (input == "how are you")
 		{
 			cout << "Chatbot: I'm doing great, thank you for asking!" << endl;
 		}
 		else if (input == "what is your name")
 		{
 			cout << "Chatbot: I am Chatbot, your assistant!" << endl;
 		}
 		else if (input == "help")
 		{
 			cout << "Chatbot: I can assist with greetings, general queries, and more." << endl;
 		}
 		else if (input == "what is the time")
 		{
 			cout << "Chatbot: I am sorry, I cannot provide real-time data." << endl;
 		}
 		else if (input == "tell me a joke")
 		{
 			cout << "Chatbot: Why don't skeletons fight each other? They don't have the guts!" << endl;
 		}
 		else if (input == "what is 2 + 2")
 		{
 			cout << "Chatbot: The answer is 4." << endl;
 		}
 		else if (input == "what is the capital of france")
 		{
 			cout << "Chatbot: The capital of France is Paris." << endl;
 		}
 		else if (input == "how to make a cup of tea")
 		{
 			cout << "Chatbot: To make a cup of tea, boil water, steep the tea bag, and enjoy!" << endl;
 		}
 		else
 		{
 			cout << "Chatbot: I'm sorry, I didn't understand that." << endl;
 		}
 	}

 	return 0;
 }