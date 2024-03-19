import os
import shutil

def copy_files_to_script_dir():
    # Get the path of the script's directory
    script_dir = os.path.dirname(os.path.realpath(__file__))
    
    # Get a list of all subdirectories
    subdirectories = [x for x in os.listdir() if os.path.isdir(x)]
    
    # Iterate through each subdirectory
    for subdir in subdirectories:
        # Get a list of all files in the subdirectory
        files = [f for f in os.listdir(subdir) if os.path.isfile(os.path.join(subdir, f))]
        
        # Iterate through each file in the subdirectory and copy it to the script's directory
        for file in files:
            src_file = os.path.join(subdir, file)
            dest_file = os.path.join(script_dir, file)
            shutil.copy(src_file, dest_file)
            print(f"Copied {src_file} to {dest_file}")

# Call the function to copy files
copy_files_to_script_dir()
