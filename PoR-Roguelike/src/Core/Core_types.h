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

/// Enumeration of AssetLoadTime
enum AssetLoadTime
{
	AssetLoadNow = 0, ///< Load the asset now
	AssetLoadLater = 1  ///< Load the asset later
};

/// Enumeration of AssetDropTime
enum AssetDropTime
{
	AssetDropUnspecified = 0, ///< Drop/unload time unspecified, use default AtZero
	AssetDropAtZero = 1, ///< Drop/unload when count reaches 0
	AssetDropAtExit = 2  ///< Drop/unload when program exits (deconstructor)
};

/// Enumeration of all Asset loading techniques
enum AssetLoadStyle
{
	AssetLoadFromUnknown = 0, ///< Error condition returned by GetLoadStyle
	AssetLoadFromFile = 1, ///< Load the asset from a file
	AssetLoadFromMemory = 2, ///< Load the asset from memory
	AssetLoadFromNetwork = 3  ///< Load the asset from the network
};

// Forward declarations
class Game;
class AScreen;


/// Declare Asset ID typedef which is used for identifying Assets
typedef std::string typeAssetID;

/// Declare Asset Handler ID typedef which is used for identifying Asset Handler objects
typedef std::string typeAssetHandlerID;
