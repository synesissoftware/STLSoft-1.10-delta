@echo off

if {%3} == {} (

	echo This script combines an STLSoft 1.9 distribution with an
	echo STLSoft 1.10 alpha delta distribution into a target directory.
	echo.
	echo NOTE: the target directory will be emptied!
	echo.
	echo USAGE: %~n0^(%~x0^) ^<1.9-dir^> ^<1.10-alpha-delta-dir^> ^<target-dir^>
	goto :eof
)

setlocal & pushd

set COMBINE_1_9_dir=%1
set COMBINE_1_10_alpha_delta_dir=%2
set COMBINE_target_dir=%3

echo.
echo emptying target directory '%COMBINE_target_dir%' ...
pushd "%COMBINE_target_dir%"
for /r %%f in (*.*) do @del /f %%f
popd

echo.
echo copying STLSoft 1.9 contents from '%COMBINE_1_9_dir%' to '%COMBINE_target_dir%'
xcopy "%COMBINE_1_9_dir%" "%COMBINE_target_dir%" /e

echo.
echo copying STLSoft 1.10 alpha delta contents from '%COMBINE_1_10_alpha_delta_dir%' to '%COMBINE_target_dir%'
xcopy "%COMBINE_1_10_alpha_delta_dir%" "%COMBINE_target_dir%" /e /y


echo.
echo combination complete
echo.

popd & endlocal

