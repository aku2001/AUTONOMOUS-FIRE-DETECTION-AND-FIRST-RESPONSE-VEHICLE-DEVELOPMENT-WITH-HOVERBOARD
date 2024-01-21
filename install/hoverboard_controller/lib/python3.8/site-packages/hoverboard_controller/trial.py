
localization_config_path = "/home/qty/ros2_ws/src/hoverboard_controller/launch/localization.launch_tmp.py"
localization_config_path_updated = "/home/qty/ros2_ws/src/hoverboard_controller/launch/localization.launch.py"
place_holder = "{MAP_FILE_NAME}"

def updateFileNameLocalization(fileName):
    print("Updating Name")
    try:
        # Read the content of the file
        print("Reading")
        with open(localization_config_path, "r") as file:
            content = file.read()
            file.close()

        # Replace the placeholder text
        updated_content = content.replace(place_holder, fileName)

        # Write the updated content back to the file
        print("Writing")

        with open(localization_config_path_updated, "w") as file:
            file.write(updated_content)
            file.close()
        
        return True
    except Exception as e:
        print(e)
        return False
    
updateFileNameLocalization("Hello")