#include "Application.h"

#include <string>

#include "Console.h"
#include "ArgumentsAnalyzer.h"

#include "PIFCompressor.h"

void Application::Start (int argc, char** argv)
{
	ArgumentsAnalyzer::Instance ()->ProcessArguments (argc, argv);

	Argument* arg = ArgumentsAnalyzer::Instance ()->GetArgument ("compress");

	if (arg != nullptr) {

		if (arg->GetArgs ().size () == 0) {
			Console::LogError ("No file to compress!");
			exit (0);
		}

		std::string inputFilename = arg->GetArgs () [0];

		Argument* arg2 = ArgumentsAnalyzer::Instance ()->GetArgument ("output");

		const std::string defaultOutputFilename = "output.piff";
		std::string outputFilename = defaultOutputFilename;
		if (arg2 != nullptr && arg2->GetArgs ().size () > 0) {
			outputFilename = arg2->GetArgs () [0];
		}

		Console::Log ("Compressing " + inputFilename + " in " + outputFilename + "...");
		PIFCompressor::Instance ()->Compress (inputFilename, outputFilename);

		return ;
	}

	arg = ArgumentsAnalyzer::Instance ()->GetArgument ("decompress");

	if (arg != nullptr) {

		if (arg->GetArgs ().size () == 0) {
			Console::LogError ("No file to decompress!");
			exit (0);
		}

		std::string inputFilename = arg->GetArgs () [0];

		Argument* arg2 = ArgumentsAnalyzer::Instance ()->GetArgument ("output");

		const std::string defaultOutputFilename = "output.tif";
		std::string outputFilename = defaultOutputFilename;
		if (arg2 != nullptr && arg2->GetArgs ().size () > 0) {
			outputFilename = arg2->GetArgs () [0];
		}

		Console::Log ("Decompressing " + inputFilename + " in " + outputFilename + "...");
		PIFCompressor::Instance ()->Decompress (inputFilename, outputFilename);

		return ;
	}
}

void Application::Quit (int argc, char** argv)
{

}