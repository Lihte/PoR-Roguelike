#include <string>

#pragma once


/// Status Enumeration for Status Return values
enum StatusType
{
	// Values from -99 to 99 are common Error and Good status responses
	StatusGameMissingAsset = -4,  ///< Application failed due to missing asset file
	StatusGameMapEmpty = -3,  ///< Application Screens stack is empty
	StatusGameInitFailed = -2,  ///< Application initialization failed
	StatusError = -1,  ///< General error status response
	StatusGameOK = 0,  ///< Application quit without error
	StatusNoError = 0,  ///< General no error status response
	StatusFalse = 0,  ///< False status response
	StatusTrue = 1,  ///< True status response
	StatusOK = 1   ///< OK status response

				   // Values from +-100 to +-199 are reserved for File status responses
};

/// Enumeration for Screen Types
enum ScreenType
{
	SCREEN_SPLASH,
	SCREEN_TITLE,
	SCREEN_GAME
};

// Forward declarations
class Game;
class AScreen;

/// Declare Asset ID typedef which is used for identifying Assets
typedef std::string typeAssetID;