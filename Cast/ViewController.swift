//
//  ViewController.swift
//  Cast
//
//  Created by Fady Basem on 6/19/17.
//  Copyright © 2017 Fady Basem Co. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIWebViewDelegate {
    //MARK: Outlets
    @IBOutlet weak var searchBar: UITextField!
    @IBOutlet weak var webView: UIWebView!
    @IBOutlet weak var cancelButton: UIButton!
    @IBOutlet weak var searchBarTrailingConstraint: NSLayoutConstraint!
    
    //MARK: Properties
    static var videoURLs: [String] = []
    
    //MARK: Methods
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        cancelButton.layer.cornerRadius = 5
        cancelButton.isHidden = true
        webView.delegate = self

    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.isNavigationBarHidden = true

    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        self.navigationController?.isNavigationBarHidden = false

    }
    
    func webViewDidFinishLoad(_ webView: UIWebView) {
        ViewController.videoURLs = []
        var videoTag = ""
        var embedTag = ""
        let htmlCode = webView.stringByEvaluatingJavaScript(from: "document.documentElement.outerHTML")
        let htmlTags = htmlCode!.components(separatedBy: "\n") as [String]
        for tag in htmlTags{
            var videoURL = ""
            if tag.contains("<video") {
                videoTag = tag.substring(from: tag.range(of: "<video")!.lowerBound)
                videoTag = videoTag.substring(to: (videoTag.range(of: ">")?.upperBound)!)
                if videoTag.contains("src"){
                    videoTag = tag.substring(from: tag.range(of: "src")!.upperBound)
                    for x in videoTag.characters{
                        if x == "\""{
                            continue
                        }else if x == "="{
                            continue
                        }else if x == ">"{
                            break
                        }else{
                            videoURL.append(x)
                        }
                    }
                }
                if !ViewController.videoURLs.contains(videoURL){
                    ViewController.videoURLs.append(videoURL)
                }
            }
            if tag.contains("<embed") {
                embedTag = tag.substring(from: tag.range(of: "<embed")!.lowerBound)
                embedTag = embedTag.substring(to: (embedTag.range(of: ">")?.upperBound)!)
                if embedTag.contains("src"){
                    embedTag = tag.substring(from: tag.range(of: "src")!.upperBound)
                    for x in embedTag.characters{
                        if x == "\""{
                            continue
                        }else if x == "="{
                            continue
                        }else if x == ">"{
                            break
                        }else{
                            videoURL.append(x)
                        }
                    }
                }
                if !ViewController.videoURLs.contains(videoURL){
                    ViewController.videoURLs.append(videoURL)
                }
            }
        }
    }
    
    //MARK: Actions
    @IBAction func cancelPressed() {
        cancelButton.isHidden = true
        searchBarTrailingConstraint.constant = 0.0
        UIView.animate(withDuration: 0.25) {
            self.view.layoutIfNeeded()
        }
        searchBar.resignFirstResponder()
    }
    
    @IBAction func searchBarPressed() {
        searchBarTrailingConstraint.constant = (cancelButton.frame.width + 8.0) * -1
        UIView.animate(withDuration: 0.25) {
            self.view.layoutIfNeeded()
        }
        cancelButton.isHidden = false
    }

    @IBAction func returnButtonPressed(_ sender: UITextField) {
        cancelPressed()
        if let url = URL(string: NSString(string: sender.text!).addingPercentEscapes(using: String.Encoding.utf8.rawValue)!){
            if UIApplication.shared.canOpenURL(url){
                var request = URLRequest(url: url)
                request.allowsCellularAccess = false
                webView.loadRequest(request)
            }else{
                let googleSearchURL = URL(string: "https://www.google.com/search?client=safari&q=\(url)&ie=UTF-8&oe=UTF-8")
                var request = URLRequest(url: googleSearchURL!)
                request.allowsCellularAccess = false
                webView.loadRequest(request)
            }
        }else{
            var searchString: [String] = []
            var searchWord = ""
            for x in (sender.text?.characters)!{
                if x == " "{
                    searchString.append(searchWord)
                    searchWord = ""
                }else{
                    searchWord.append(x)
                }
            }
            //For appending the last word not followed by a space
            if !(searchString.last == searchWord){
                searchString.append(searchWord)
            }
            var googleSearchURL = "https://www.google.com/search?client=safari&ie=UTF-8&oe=UTF-8&q="
            for element in searchString{
                googleSearchURL.append(element)
                if !(searchString.last == element){
                    googleSearchURL.append("+")
                }
                
            }
            var request = URLRequest(url: URL(string:googleSearchURL)!)
            request.allowsCellularAccess = false
            webView.loadRequest(request)
        }
    }
    
    @IBAction func backButtonPressed(_ sender: UIButton) {
        if webView.canGoBack{
            webView.goBack()
        }
    }
    
    @IBAction func forwardButtonPressed(_ sender: UIButton) {
        if webView.canGoForward {
            webView.goForward()
        }
    }
    
}

