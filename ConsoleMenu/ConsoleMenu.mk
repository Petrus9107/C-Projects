##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ConsoleMenu
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace
ProjectPath            :=C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace/ConsoleMenu
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Erwin
Date                   :=26/02/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ConsoleMenu.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Frame.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextField.cpp$(ObjectSuffix) $(IntermediateDirectory)/SubMenu.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace/ConsoleMenu/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Frame.cpp$(ObjectSuffix): Frame.cpp $(IntermediateDirectory)/Frame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace/ConsoleMenu/Frame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Frame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Frame.cpp$(DependSuffix): Frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Frame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Frame.cpp$(DependSuffix) -MM Frame.cpp

$(IntermediateDirectory)/Frame.cpp$(PreprocessSuffix): Frame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Frame.cpp$(PreprocessSuffix) Frame.cpp

$(IntermediateDirectory)/TextField.cpp$(ObjectSuffix): TextField.cpp $(IntermediateDirectory)/TextField.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace/ConsoleMenu/TextField.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextField.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextField.cpp$(DependSuffix): TextField.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextField.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextField.cpp$(DependSuffix) -MM TextField.cpp

$(IntermediateDirectory)/TextField.cpp$(PreprocessSuffix): TextField.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextField.cpp$(PreprocessSuffix) TextField.cpp

$(IntermediateDirectory)/SubMenu.cpp$(ObjectSuffix): SubMenu.cpp $(IntermediateDirectory)/SubMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Erwin/Desktop/NaukaProgramowania/C++/Projekty/CodeLite_Projects/CLiteWorkspace/ConsoleMenu/SubMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SubMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SubMenu.cpp$(DependSuffix): SubMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SubMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SubMenu.cpp$(DependSuffix) -MM SubMenu.cpp

$(IntermediateDirectory)/SubMenu.cpp$(PreprocessSuffix): SubMenu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SubMenu.cpp$(PreprocessSuffix) SubMenu.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


