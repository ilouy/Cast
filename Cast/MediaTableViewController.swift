//
//  MediaTableViewController.swift
//  Cast
//
//  Created by Fady Basem on 6/24/17.
//  Copyright © 2017 Fady Basem Co. All rights reserved.
//

import UIKit
import AVFoundation
import GoogleCast

class MediaTableViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    var videoScreenshots: UIImage!
        
    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.tableView.dataSource = self
        self.tableView.delegate = self
        
        let frame = CGRect(x: CGFloat(0), y: CGFloat(0), width: CGFloat(24), height: CGFloat(24))
        let castButton = GCKUICastButton(frame: frame)
        //castButton.tintColor = UIColor.blue
        let item = UIBarButtonItem(customView: castButton)
        navigationItem.rightBarButtonItem = item
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        tableView.reloadData()
        
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 15
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell") as! MediaTableViewCell
        
        if ViewController.videoURLs.indices.contains(indexPath.row){
            cell.videoURL.text = ViewController.videoURLs[indexPath.row]
            
        }
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.cellForRow(at: indexPath)?.isSelected = false
        
        let cell = tableView.cellForRow(at: indexPath) as! MediaTableViewCell
        
        let metadata = GCKMediaMetadata(metadataType: .generic)
        metadata.setString(cell.videoURL.text!, forKey: kGCKMetadataKeyTitle)
        
        var asset: AVURLAsset!
        
        let nsurl = NSString(string: cell.videoURL.text!)
        
        if let url = URL(string: nsurl as String){
            asset = AVURLAsset(url: url)
        }
        
        var contentType = ""
        
        switch nsurl.pathExtension{
        case ".flv":
            contentType = "video/x-flv"
        case ".mp4":
            contentType = "video/mp4"
        case ".m3u8":
            contentType = "application/x-mpegURL"
        case ".ts":
            contentType = "video/MP2T"
        case ".3gp":
            contentType = "video/3gpp"
        case ".mov":
            contentType = "video/quicktime"
        case ".avi":
            contentType = "video/x-msvideo"
        case ".wmv":
            contentType = "video/x-ms-wmv"
        default:
            break
            
        }
        
        var mediaInformation: GCKMediaInformation!
        
        if asset != nil{
        
            mediaInformation = GCKMediaInformation.init(contentID: cell.videoURL.text!, streamType: .unknown, contentType: contentType , metadata: metadata, streamDuration: asset.duration.seconds, customData: nil)
            
            
            let session: GCKCastSession? = GCKCastContext.sharedInstance().sessionManager.currentCastSession
            
            if session != nil {
                session?.remoteMediaClient?.loadMedia(mediaInformation)
            }
                
        }
        
    }
}
