import mosspy

# Your MOSS user ID (replace with your own MOSS ID)
userid = 987654321  

# Initialize MOSS for C++
m = mosspy.Moss(userid, "cc")  # 'cc' is for C++

# Add the base file (optional, used to ignore common code)
m.addBaseFile("base.cpp")

# Add the file to check for similarity
m.addFile("Beautiful_Garden.cpp")

# Send files to MOSS
url = m.send(lambda file_path, display_name: print('*', end='', flush=True))
print("\nReport URL:", url)

# Optionally save the web page of the report
m.saveWebPage(url, "report.html")

# Optionally download the full report (with code diffs, etc.)
mosspy.download_report(url, "report/", connections=8, log_level=10, 
                       on_read=lambda url: print('*', end='', flush=True))
