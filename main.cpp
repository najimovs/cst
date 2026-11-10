#include <array>
#include <cstdio>
#include <iostream>
#include <optional>
#include <print>
#include <sstream>
#include <string>
#include <string_view>

struct Question {
	std::string_view text;
	std::array<std::string_view, 4> options;
	int correct_answer;
};

constexpr std::array<Question, 5> questions{
	{
		{
			"What does global warming mean?",
			{
				"Earth gets colder",
				"Earth gets warmer",
				"Earth gets smaller",
				"Earth stops moving"
			},
			2
		},
		{
			"What can global warming do to the ice at Earth's poles?",
			{
				"Make it melt",
				"Make it colder",
				"Make it grow bigger",
				"Turn it into rock"
			},
			1
		},
		{
			"Which action adds gases that make Earth warmer?",
			{
				"Planting trees",
				"Riding a bike",
				"Burning coal and oil",
				"Walking to school"
			},
			3
		},
		{
			"Which way to travel does not burn fuel?",
			{
				"A petrol car",
				"A diesel bus",
				"A motorbike",
				"Walking"
			},
			4
		},
		{
			"Which action helps protect our planet?",
			{
				"Cutting down forests",
				"Planting trees",
				"Burning rubbish",
				"Wasting electricity"
			},
			2
		},
	}
};

std::optional<int> read_answer() {

	std::string line;

	while ( true ) {

		std::print( "Your answer (1-4): " );
		std::fflush( stdout );

		if ( !std::getline( std::cin, line ) ) {

			return std::nullopt;
		}

		std::istringstream input{ line };
		int answer{};
		char extra{};

		if ( ( input >> answer ) && !( input >> extra ) && answer >= 1 && answer <= 4 ) {

			return answer;
		}

		std::println( "Invalid input. Enter one integer from 1 to 4." );
	}
}

int main() {

	std::println( "Global Warming Quiz\n"
		"Answer five questions. Enter each answer on a separate line." );

	int score = 0;

	for ( std::size_t i = 0; i < questions.size(); ++i ) {

		const auto& question = questions[ i ];

		std::println( "\n{}. {}", i + 1, question.text );

		for ( std::size_t j = 0; j < question.options.size(); ++j ) {

			std::println( "  {}) {}", j + 1, question.options[ j ] );
		}

		const auto answer = read_answer();

		if ( !answer ) {

			std::println( "\nInput ended. Quiz was not completed." );

			return 1;
		}

		if ( *answer == question.correct_answer ) {

			++score;
		}
	}

	std::println( "\nCorrect answers: {}/{}", score, questions.size() );

	if ( score == 5 ) {

		std::println( "Excellent" );
	}
	else if ( score == 4 ) {

		std::println( "Very good" );
	}
	else {

		std::println( "Time to brush up on your knowledge of global warming" );
	}

	return 0;
}
