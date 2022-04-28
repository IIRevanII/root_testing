{
    //constructor: TGraphErrors(const char *filename, const char *format="%lg %lg %lg %lg", Option_t *option="");
    TGraphErrors test_input("Test_data.txt", "%lg %lg %lg", "");

    // Instance of the graph
    test_input.SetTitle("Measurement XYZ;length [cm];Arb.Units");

    // Make the plot esthetically better
    test_input.SetMarkerStyle(kOpenCircle);
    test_input.SetMarkerColor(kBlue);
    test_input.SetLineColor(kBlue);

    //Kleine Doku zu Graphen zeichnen

    //---------------------Farben---------------------------
    //https://root.cern/doc/master/classTColor.html#C00

    //Man kann unterschiedliche Styles machen, die auf neu erstellte Objekte angewand werden
    //mit TStyle kann man neue Styles erstellen
     //gROOT->SetStyle("Plain"); // Set the current style to "Plain"
     //canvas->UseCurrentStyle();

    //--------------Axen------------------------------------
    //https://root.cern/doc/master/classTGaxis.html#GA14
    //axis->SetTitle("My axis title");
    //If the axis is embedded into a histogram or a graph, you first have to extract the axis object.
    //histo->GetXaxis()->SetTitle("My axis title")
    //axis->SetLabelColor(kRed); // change the labels'color to red
    //axis->SetNdivisions(510); // Set 10 primary divisions and 5 secondary divisions.
    //Use TAxis::SetRange() or TAxis::SetRangeUser() to zoom the axis. für Histogramme
    //im link wird auch gezeigt wie man die Axen z.B. zu Zeitachsen ändern kann

    //-------------Legenden--------------------------------
    //https://root.cern/doc/master/classTLegend.html
    //The method BuildLegend automatically build a TLegend with all the objects present in a TPad .


    //--------------Canvas----------------------------------
    //https://root.cern/doc/master/classTCanvas.html#a7d4d72e9a1f81b2bf7c36cc08521bedb
    // 1. Wichtig: https://root.cern/doc/master/classTCanvas.html
    // hat unterschiedliche Constructoren
    // btw wenn du mehrere von den Dingern hast, dann wird immer auf das zuletzt definierte gemalt

    //der folgende Constructor nimmt als Parameter: Name, Titel, 2 x Position auf Bildschirm, 2 x Größe des Fensters
    TCanvas c1("Random plot" , "Test Mesurements", 300, 300, 800, 500);
    //TCanvas c2("Random plot" , "Test Mesurements", 400, 400, 200, 100);

    //macht dir ne Toolbar mit der du das Ding noch weiter bearbeiten kannst. z.B. Pfeile
    //c1.ToggleToolBar();

    //zoomed rein und lässt dich dann scrollen
    //c1.SetCanvasSize(1500, 1500);
    //c1.SetWindowSize(500, 500);

    //Funktioniert irgendwie nicht

    //c2.UseCurrentStyle();
    //c1.SetFixedAspectRatio();
    //c1.SetFolder(kTRUE);
    //c1.SetGrayscale(kTRUE);
    //c1.SetHighLightColor(13);
    //c1.SetName("LOL");

    //Funktioniert tatsächlich
    c1.SetRealAspectRatio(1);           //fancy :D, 1 für Axe 1 und 2 für Axe 2
    //c1.SetTitle("LOL");               //selbe wie im Constructor
    c1.SetGrid();
    c1.SetFillColor(40);
    c1.Draw();

    //---------------------Pads------------------------------
    // der Canvas kann in mehrere Pads unterteilt werden um Plots nebeneinander zu haben https://root.cern/doc/master/classTPad.html#a2714ddd7ba72d5def84edc1fbaea8658
    // man kann mit cd() das Pad auswählen das man bearbeitet (current pad)

    //ein Pad ist eine linked list of references to original objects
    //Adding a new element into a pad is in general performed by the Draw member function of the object classes
    //The effective drawing is performed when the canvas receives a signal to be painted
    //When an object is drawn, it is always in the so-called active pad.
    



    test_input.Draw();

    //sollte eigentlich funktionieren aber kp
    //c1.show();
}