#pragma once
#include <string>
#include <storm.h>
#include <fstream>

// Functions
std::string LoadConfigString(const char *pszKey, const char *pszItem, const char *pszDefault = NULL);
std::string LoadConfigStringUCase (const char *pszKey, const char *pszItem, const char *pszDefault = NULL);
int LoadConfigInt(const char *pszKey, const char *pszItem, const int iDefault = 0);
std::string LoadRegString(const char *pszKeyName, const char *pszValueName);

void InitPrimaryConfig();

// Data
inline const std::string& installPath()
{
  //static const std::string path = LoadRegString("starcraft", "InstallPath") + "\\";
  std::string sInstallPath;


  std::ofstream test2("runfrom.txt");
  test2 << "test";
  test2.close();

  std::ifstream test("settings.txt");
  test >> sInstallPath;
  test.close();
  return sInstallPath;
}
inline const std::string& configPath()
{
  static const std::string path = installPath() + "bwapi-data\\bwapi.ini";
  return path;
}
extern std::string screenshotFmt;

extern bool isCorrectVersion;
extern bool showWarn;
extern bool serverEnabled;
extern unsigned gdwProcNum;

