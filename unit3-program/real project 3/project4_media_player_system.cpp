// ============================================================================
// Unit III - Mini-Project: Media Player with Polymorphic Controls
// ============================================================================
// Description: Demonstrates runtime polymorphism, abstract base classes,
// virtual functions, and smart pointer collection management for a Media Player
// system supporting Audio, Video, and Image media types.
// ============================================================================

// Include standard input-output stream library for console logging and status display
#include <iostream>

// Include memory library for modern smart pointers (std::unique_ptr and std::make_unique)
#include <memory>

// Include string library for handling titles, artists, formats, and resolutions
#include <string>

// Include vector container library for dynamic collection storage of Media objects
#include <vector>

// Use standard namespace to prevent repeating std:: before standard functions and types
using namespace std;

// Abstract base class representing generic media item in the media player
class Media {
protected:
    // Protected data member storing the title of the media file
    string title;

    // Protected data member storing duration of media in seconds (or display duration for images)
    double duration;

public:
    // Parameterized constructor initializing base media properties using member initializer list
    Media(string t, double d) : title(t), duration(d) {}

    // Pure virtual function to start media playback; makes Media an abstract class
    virtual void play() const = 0;

    // Pure virtual function to pause active media playback
    virtual void pause() const = 0;

    // Pure virtual function to stop media playback
    virtual void stop() const = 0;

    // Pure virtual function to display detailed metadata about the media item
    virtual void showDetails() const = 0;

    // Virtual destructor ensuring correct destruction of derived class objects via base pointer
    virtual ~Media() = default;
};

// Derived class representing Audio media files (e.g. MP3, WAV, FLAC)
class Audio : public Media {
private:
    // Private data member storing name of performing artist or composer
    string artist;

    // Private data member storing audio bitrate in kilobits per second (kbps)
    int bitrateKbps;

public:
    // Parameterized constructor passing title & duration to base class and initializing artist & bitrate
    Audio(string t, double d, string a, int b)
        : Media(t, d), artist(a), bitrateKbps(b) {}

    // Overridden play() method implementing audio playback simulation
    void play() const override {
        // Output audio playing status with title and artist
        cout << "[Audio] Playing audio: \"" << title << "\" by " << artist << endl;
    }

    // Overridden pause() method implementing audio pause simulation
    void pause() const override {
        // Output audio paused status
        cout << "[Audio] Paused audio stream: \"" << title << "\"" << endl;
    }

    // Overridden stop() method implementing audio stop simulation
    void stop() const override {
        // Output audio stopped status
        cout << "[Audio] Stopped playback: \"" << title << "\"" << endl;
    }

    // Overridden showDetails() method outputting metadata specific to Audio files
    void showDetails() const override {
        // Output formatted metadata including title, artist, duration, and bitrate
        cout << "Type: Audio | Title: " << title
             << " | Artist: " << artist
             << " | Duration: " << duration << "s"
             << " | Bitrate: " << bitrateKbps << " kbps" << endl;
    }
};

// Derived class representing Video media files (e.g. MP4, MKV)
class Video : public Media {
private:
    // Private data member storing video display resolution (e.g., "1920x1080", "3840x2160")
    string resolution;

    // Private data member storing video frame rate in frames per second (fps)
    int frameRate;

public:
    // Parameterized constructor passing title & duration to base class and initializing video attributes
    Video(string t, double d, string res, int fps)
        : Media(t, d), resolution(res), frameRate(fps) {}

    // Overridden play() method implementing video playback simulation
    void play() const override {
        // Output video playback status with title and resolution
        cout << "[Video] Playing video: \"" << title << "\" [" << resolution << " @ " << frameRate << "fps]" << endl;
    }

    // Overridden pause() method implementing video pause simulation
    void pause() const override {
        // Output video freeze-frame pause status
        cout << "[Video] Paused video frame: \"" << title << "\"" << endl;
    }

    // Overridden stop() method implementing video stop simulation
    void stop() const override {
        // Output video playback termination status
        cout << "[Video] Stopped video rendering: \"" << title << "\"" << endl;
    }

    // Overridden showDetails() method outputting metadata specific to Video files
    void showDetails() const override {
        // Output formatted metadata including title, duration, resolution, and FPS
        cout << "Type: Video | Title: " << title
             << " | Duration: " << duration << "s"
             << " | Resolution: " << resolution
             << " | Frame Rate: " << frameRate << " fps" << endl;
    }
};

// Derived class representing Image media files (e.g. JPEG, PNG)
class Image : public Media {
private:
    // Private data member storing image file format/extension (e.g., "PNG", "JPEG")
    string imageFormat;

    // Private data member storing image dimensions (e.g., "1920x1080")
    string dimensions;

public:
    // Parameterized constructor passing title & display duration to base class and initializing image parameters
    Image(string t, double displayDuration, string fmt, string dim)
        : Media(t, displayDuration), imageFormat(fmt), dimensions(dim) {}

    // Overridden play() method implementing image viewing / slideshow presentation simulation
    void play() const override {
        // Output image display status
        cout << "[Image] Displaying image on screen: \"" << title << "." << imageFormat << "\"" << endl;
    }

    // Overridden pause() method implementing slideshow hold simulation
    void pause() const override {
        // Output image slideshow hold status
        cout << "[Image] Holding current slideshow image: \"" << title << "\"" << endl;
    }

    // Overridden stop() method implementing image viewer close simulation
    void stop() const override {
        // Output image viewer close status
        cout << "[Image] Closed image viewer for: \"" << title << "\"" << endl;
    }

    // Overridden showDetails() method outputting metadata specific to Image files
    void showDetails() const override {
        // Output formatted metadata including title, format, dimensions, and display duration
        cout << "Type: Image | Title: " << title
             << " | Format: " << imageFormat
             << " | Dimensions: " << dimensions
             << " | Display Time: " << duration << "s" << endl;
    }
};

// Main function: Program entry point managing polymorphic media playlist operations
int main() {
    // Declare vector of unique pointers storing polymorphically managed Media items
    vector<unique_ptr<Media>> playlist;

    // Add Audio track object to playlist using make_unique dynamic allocation
    playlist.push_back(make_unique<Audio>("Bohemian Rhapsody", 354.0, "Queen", 320));

    // Add Video clip object to playlist using make_unique dynamic allocation
    playlist.push_back(make_unique<Video>("C++ Polymorphism Tutorial", 600.0, "1920x1080", 60));

    // Add Image picture object to playlist using make_unique dynamic allocation
    playlist.push_back(make_unique<Image>("Sunset Beach", 10.0, "JPEG", "3840x2160"));

    // Output header banner for playlist details section
    cout << "=== Polymorphic Media Player Playlist Details ===" << endl;
    // Iterate through playlist dynamic collection using range-based loop over const unique_ptr references
    for (const auto& item : playlist) {
        // Call showDetails() polymorphically via base class Media pointer
        item->showDetails();
    }

    // Output header banner for media player playback controls section
    cout << "\n=== Executing Polymorphic Playback Operations ===" << endl;
    // Iterate through playlist items to execute polymorphic play, pause, and stop controls
    for (const auto& item : playlist) {
        // Invoke polymorphic play() implementation for current media type
        item->play();

        // Invoke polymorphic pause() implementation for current media type
        item->pause();

        // Invoke polymorphic stop() implementation for current media type
        item->stop();

        // Output separator line between playback controls of different items
        cout << "--------------------------------------------------" << endl;
    }

    // Return 0 indicating successful completion of main function
    return 0;
}
