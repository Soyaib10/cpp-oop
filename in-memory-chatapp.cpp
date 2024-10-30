/*Design a simple class based in-memory solution for a basic chat application
- you can create users in the system using phone number and their name
- one user can send a message to another user
- a user can see their list of messages from different users, the messages should be ordered with most recent first
- given a list of messages, return a list of "top 10 friends" based on the number of messages users are sending each other. create a function which takes the list of messages as input, and returns a list of up to 10 top friends. Here if a person 1 sends a message to person 2, should be treated the same if person 2 sends a message to person 1. Here are the sample inputs and outputs:
// sample input
[
  {
    senderName: "John",
    senderPhone: "01717001473",
    receiverName: "jane",
    receiverPhone: "01717001472",
    text: "hello!"
  },
  {
    senderName: "Jane",
    senderPhone: "01717001472",
    receiverName: "jane",
    receiverPhone: "01717001473",
    text: "hi!"
  },
  // more similar message objects here
]
// sample output
[
  {
    personA: "John",
    personAPhone: "01717001473",
    personB: "Jane",
    personBPhone: "01717001472",
    numberOfMessages: 2
  }
]
*/
#include<bits/stdc++.h>
using namespace std;

class User {
public:
	string name;
	string phone;

	User() : name(""), phone("") {} // Default constructor
	User(string name, string phone) : name(name), phone(phone) {}
};

class Message {
public:
	string senderPhone;
	string receiverPhone;
	string text;

	Message(string senderPhone, string receiverPhone, string text)
		: senderPhone(senderPhone), receiverPhone(receiverPhone), text(text) {}
};

class ChatApp {
private:
	unordered_map<string, User> users;                         // Store users by phone number
	unordered_map<string, vector<Message>> userMessages;       // Store messages by phone number pair
	map<pair<string, string>, int> messageCount;               // Count messages between each pair

public:
	void createUser(string name, string phone) {
		if (users.find(phone) == users.end()) {
			users[phone] = User(name, phone);
			cout << "User created: " << name << " (" << phone << ")\n";
		} else {
			cout << "User with phone " << phone << " already exists.\n";
		}
	}

	void sendMessage(string senderPhone, string receiverPhone, string text) {
		if (users.find(senderPhone) == users.end() || users.find(receiverPhone) == users.end()) {
			cout << "Sender or receiver does not exist.\n";
			return;
		}

		Message message(senderPhone, receiverPhone, text);
		userMessages[senderPhone].push_back(message);
		userMessages[receiverPhone].push_back(message);

		pair<string, string> key = make_pair(min(senderPhone, receiverPhone), max(senderPhone, receiverPhone));
		messageCount[key]++;
	}

	vector<Message> getMessages(string userPhone) {
		vector<Message> messages = userMessages[userPhone];
		sort(messages.begin(), messages.end(), [](Message & a, Message & b) { return a.text > b.text; });
		return messages;
	}

	vector<map<string, string>> getTop10Friends() {
		vector<pair<pair<string, string>, int>> countVector(messageCount.begin(), messageCount.end());

		sort(countVector.begin(), countVector.end(),
		[](auto & a, auto & b) { return a.second > b.second; });

		vector<map<string, string>> topFriends;
		for (int i = 0; i < min(10, (int)countVector.size()); i++) {
			auto &[userPair, count] = countVector[i];
			string personA = users[userPair.first].name;
			string personB = users[userPair.second].name;

			topFriends.push_back({
				{"personA", personA},
				{"personAPhone", userPair.first},
				{"personB", personB},
				{"personBPhone", userPair.second},
				{"numberOfMessages", to_string(count)}
			});
		}

		return topFriends;
	}
};

int main() {
	ChatApp app;

	// Create users
	app.createUser("John", "01717001473");
	app.createUser("Jane", "01717001472");

	// Send messages
	app.sendMessage("01717001473", "01717001472", "hello!");
	app.sendMessage("01717001472", "01717001473", "hi!");

	// Get messages of a user
	vector<Message> johnMessages = app.getMessages("01717001473");
	cout << "John's Messages:\n";
	for (const auto &message : johnMessages) {
		cout << message.text << "\n";
	}

	// Get top 10 friends
	vector<map<string, string>> topFriends = app.getTop10Friends();
	cout << "\nTop Friends:\n";
	for (const auto &entry : topFriends) {
		cout << entry.at("personA") << " and " << entry.at("personB")
		     << " - Messages: " << entry.at("numberOfMessages") << "\n";
	}

	return 0;
}
